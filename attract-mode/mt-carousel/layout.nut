///////////////////////////////////////////////////
//
// Attract-Mode Frontend - Carousel layout
//
///////////////////////////////////////////////////
class UserConfig {
	</ label="Background image", help="Background image", options="default", order=1 />
  bg_img="default.png";
  
  </ label="Artwork Type", help="Artwork to display", options="snap,marquee,flyer,wheel", per_display="true", order=2 />
  art="flyer";
  
  </ label="Artwork Width", help="The width at which the artwork will be displayed", per_display="true", order=3 />
  artwork_width="256";

  </ label="Artwork Height", help="The height at which the artwork will be displayed", per_display="true", order=4 />
  artwork_height="256";
  
  </ label="Artwork Gap", help="Space in between artworks", per_display="true", order=5 />
  artwork_gap="8";

  </ label="Transition Time", help="The amount of time (in milliseconds) that it takes to scroll to another carousel entry", per_display="true", order=6 />
  transition_ms="150";
}

fe.load_module("conveyor");

local my_config = fe.get_config();
local transition_ms = my_config["transition_ms"].tointeger();
local artwork_gap = my_config["artwork_gap" ].tointeger();
local artwork_height = my_config["artwork_height"].tointeger();
local artwork_width = my_config["artwork_width"].tointeger();
local bg_img = my_config["bg_img"];

local cols = fe.layout.width / artwork_width;
local paddedCols = cols + 2;
local rows = 1;

local artwork_half_gap = artwork_gap / 2;
local carousel_y = (fe.layout.height - artwork_height) / 2;
// local carousel_x = (fe.layout.width - paddedCols * (artwork_width + artwork_gap)) / 2;
local carousel_x = - (artwork_width + artwork_gap) * 3 / 4;

fe.add_image(bg_img, 0, 0, fe.layout.width, fe.layout.height);

class Carousel extends Conveyor {
  frame_top=null;
  frame_bottom=null;
  name_t=null;
  num_t=null;
  title_t=null;
  controls_y=null;
  sel_x=0;

  constructor() {
    base.constructor();

    sel_x = paddedCols / 2;

    stride = fe.layout.page_size = rows;
    fe.add_signal_handler(this, "on_signal");
  }

  function update_frame() {
    frame_top.x = carousel_x + artwork_width * sel_x;
    frame_top.y = carousel_y;
    
    frame_bottom.x = carousel_x + artwork_width * sel_x;
    frame_bottom.y = carousel_y + artwork_height - artwork_width;
    
    name_t.index_offset = num_t.index_offset = get_sel() - selection_index;  
  }

  function do_correction() {
    local corr = get_sel() - selection_index;
    foreach (o in m_objs) {
      local idx = o.m_art.index_offset - corr;
      o.m_art.rawset_index_offset(idx);
    }
  }

  function get_sel() {
    return sel_x * rows;
  }

  function on_signal(sig) {
    switch (sig) {
      case "exit":
      case "exit_no_menu":
      case "toggle_mute":
      case "toggle_flip":
      case "toggle_rotate_left":
      case "toggle_rotate_right":
        break;
      case "select":
      default:
        // Correct the list index if it doesn't align with
        // the game our frame is on
        //
        enabled=false; // turn conveyor off for this switch
        local frame_index = get_sel();
        fe.list.index += frame_index - selection_index;

        set_selection(frame_index);
        update_frame();
        enabled=true; // re-enable conveyor

        break;
    }

    return false;
  }

  function on_transition(transition_type, var, transition_time) {
    switch (transition_type) {
      case Transition.StartLayout:
      case Transition.FromGame:
        if (transition_time < transition_ms) {
          for (local i=0; i< m_objs.len(); i++) {
            local r = i % rows;
            local c = i / rows;
            local num = rows + cols - 2;
            if (num < 1) {
              num = 1;
            }

            local temp = 510 * (num - r - c) / num * transition_time / transition_ms;
            m_objs[i].set_alpha((temp > 255) ? 255 : temp);
          }

          return true;
        }

        local old_alpha = m_objs[ m_objs.len()-1 ].m_art.alpha;

        foreach (o in m_objs) {
          o.set_alpha(255);
        }

        if (old_alpha != 255) {
          return true;
        }

        break;

      case Transition.ToGame:
      case Transition.EndLayout:
        if (transition_time < transition_ms) {
          for (local i=0; i< m_objs.len(); i++) {
            local r = i % rows;
            local c = i / rows;
            local num = rows + cols - 2;
            if (num < 1) {
              num = 1;
            }

            local temp = 255 - 510 * (num - r - c) / num * transition_time / transition_ms;
            m_objs[i].set_alpha((temp < 0) ? 0 : temp);
          }
          return true;
        }

        local old_alpha = m_objs[ m_objs.len()-1 ].m_art.alpha;

        foreach (o in m_objs) {
          o.set_alpha(0);
        }

        if (old_alpha != 0) {
          return true;
        }

        break;
    }

    return base.on_transition(transition_type, var, transition_time);
  }
}

::carousel <- Carousel();

class Carousel extends ConveyorSlot {
  m_num = 0;
  m_shifted = false;
  m_art = null;

  constructor(num) {
    m_num = num;

    m_art = fe.add_artwork(
      my_config["art"],
      0,
      0,
      artwork_width - artwork_gap,
      artwork_height - artwork_gap
    );
    m_art.preserve_aspect_ratio = true;
    m_art.alpha = 0;

    base.constructor();
  }

  function on_progress(progress, var) {
    if (var == 0) {
      m_shifted = false
    };

    local r = m_num % rows;
    local c = m_num / rows;

    if (abs(var) < rows) {
      m_art.x = carousel_x + c * artwork_width + artwork_half_gap;
      m_art.y = carousel_y + (progress * cols - c) + artwork_half_gap;

    } else {
      local prog = ::carousel.transition_progress;
      if (prog > ::carousel.transition_swap_point) {
        if (var > 0) c++;
        else c--;
      }

      if (var > 0) prog *= -1;

      m_art.x = carousel_x + (c + prog) * artwork_width + artwork_half_gap;
      m_art.y = carousel_y + r * artwork_height + artwork_half_gap;
    }
  }

  function swap(other) {
    m_art.swap(other.m_art);
  }

  function set_index_offset(io) {
    m_art.index_offset = io;
  }

  function reset_index_offset() {
    m_art.rawset_index_offset(m_base_io); 
  }

  function set_alpha(alpha) {
    m_art.alpha = alpha; 
  }

}

local my_array = [];
for (local i = 0; i < rows * paddedCols; i++) {
  my_array.push(Carousel(i));
}

local text_h = 32;

local title_y = 16;
carousel.title_t = fe.add_text(
  "[DisplayName]/[FilterName]",
  0,
  title_y,
  fe.layout.width * 7/8,
  text_h
);
carousel.title_t.align = Align.Left;

local num_t = fe.add_text(
  "[ListEntry]/[ListSize]",
  fe.layout.width * 7/8,
  title_y,
  fe.layout.width * 1/8,
  text_h
);
num_t.align = Align.Right;
carousel.num_t = num_t;

local name_y = fe.layout.height - text_h - 16;
local name_t = fe.add_text(
  "[Title]",
  0,
  name_y,
  fe.layout.width,
  text_h
);
carousel.name_t = name_t;

local controls_y = name_y - 56;
local controls_t = fe.add_text(
  "Default controls: RIGHT (Next Game) / Left (Previous Game) / UP (Next Display) / DOWN (Previous Display)",
  0,
  controls_y,
  fe.layout.width,
  text_h * 0.75
);
controls_t.set_rgb(128, 128, 128);
carousel.controls_t = controls_t;

carousel.set_slots(my_array, carousel.get_sel());

carousel.frame_top=fe.add_image("frame_top.png", 0, 0, artwork_width, artwork_width);
carousel.frame_top.smooth = false;

carousel.frame_bottom=fe.add_image("frame_bottom.png", 0, 0, artwork_width, artwork_width);
carousel.frame_bottom.smooth = false;

carousel.update_frame();
