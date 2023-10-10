///////////////////////////////////////////////////
//
// Attract-Mode Frontend - Carousel layout
//
///////////////////////////////////////////////////
class UserConfig </ help="" />{
  </ label="Artwork Type", help="Artwork to display", options="snap,marquee,flyer,wheel", order=1 />
  art="flyer";
  
  </ label="Artwork Gap", help="Space in between artworks", order=2 />
  carouselGap="8";
  
  </ label="Artwork Width", help="The width at which the artwork will be displayed", order=3 />
  width="256";

  </ label="Artwork Height", help="The height at which the artwork will be displayed", order=4 />
  height="256";

  </ label="Transition Time", help="The amount of time (in milliseconds) that it takes to scroll to another carousel entry", order=5 />
  ttime="150";
}

fe.load_module( "conveyor" );

local my_config = fe.get_config();
local  transition_ms = my_config["ttime"].tointeger();
local carouselGap = my_config[ "carouselGap" ].tointeger();
local height = my_config[ "height" ].tointeger();
local width = my_config[ "width" ].tointeger();

local cols = fe.layout.width / width;
local paddedCols = cols + 1;
local rows = 1;

local carouselHalfGap = carouselGap / 2;
local carouselY = (fe.layout.height - height) / 2;
// local carouselX = (fe.layout.width - (width * paddedCols) - (carouselGap * (paddedCols - 1))) / 2;
local carouselX = 0;

class Carousel extends Conveyor
{
  frame=null;
  name_t=null;
  num_t=null;
  sel_x=0;
  sel_y=0;

  constructor()
  {
    base.constructor();

    sel_x = cols / 2;
    sel_y = rows / 2;

    stride = fe.layout.page_size = rows;
    fe.add_signal_handler( this, "on_signal" );
  }

  function update_frame()
  {
    frame.x = carouselX + width * sel_x;
    frame.y = carouselY + height * sel_y;
    
    name_t.index_offset = num_t.index_offset = get_sel() - selection_index;  
  }

  function do_correction()
  {
    local corr = get_sel() - selection_index;
    foreach ( o in m_objs )
    {
      local idx = o.m_art.index_offset - corr;
      o.m_art.rawset_index_offset( idx );
    }
  }

  function get_sel()
  {
    return sel_x * rows + sel_y;
  }

  function on_signal( sig )
  {
    switch ( sig )  
    {
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

      set_selection( frame_index );
      update_frame();
      enabled=true; // re-enable conveyor

      break;
    }

    return false;
  }

  function on_transition( ttype, var, ttime )
  {
    switch ( ttype )
    {
    case Transition.StartLayout:
    case Transition.FromGame:
      if ( ttime < transition_ms )
      {
        for ( local i=0; i< m_objs.len(); i++ )
        {
          local r = i % rows;
          local c = i / rows;
          local num = rows + cols - 2;
          if ( num < 1 )
            num = 1;

          local temp = 510 * ( num - r - c ) / num * ttime / transition_ms;
          m_objs[i].set_alpha( ( temp > 255 ) ? 255 : temp );
        }

        frame.alpha = 255 * ttime / transition_ms;
        return true;
      }

      local old_alpha = m_objs[ m_objs.len()-1 ].m_art.alpha;

      foreach ( o in m_objs )
        o.set_alpha( 255 );

      frame.alpha = 255;

      if ( old_alpha != 255 )
        return true;

      break;

    case Transition.ToGame:
    case Transition.EndLayout:
      if ( ttime < transition_ms )
      {
        for ( local i=0; i< m_objs.len(); i++ )
        {
          local r = i % rows;
          local c = i / rows;
          local num = rows + cols - 2;
          if ( num < 1 )
            num = 1;

          local temp = 255 - 510 * ( num - r - c ) / num * ttime / transition_ms;
          m_objs[i].set_alpha( ( temp < 0 ) ? 0 : temp );
        }
        frame.alpha = 255 - 255 * ttime / transition_ms;
        return true;
      }

      local old_alpha = m_objs[ m_objs.len()-1 ].m_art.alpha;

      foreach ( o in m_objs )
        o.set_alpha( 0 );

      frame.alpha = 0;

      if ( old_alpha != 0 )
        return true;

      break;
    }

    return base.on_transition( ttype, var, ttime );
  }
}

::carouselc <- Carousel();

class MySlot extends ConveyorSlot
{
  m_num = 0;
  m_shifted = false;
  m_art = null;

  constructor( num )
  {
    m_num = num;

    m_art = fe.add_artwork(
      my_config["art"],
      0,
      0,
      width - carouselGap,
      height - carouselGap
    );

    m_art.preserve_aspect_ratio = true;

    m_art.alpha = 0;

    base.constructor();
  }

  function on_progress( progress, var )
  {
    if ( var == 0 )
      m_shifted = false;

    local r = m_num % rows;
    local c = m_num / rows;

    if ( abs( var ) < rows )
    {
      m_art.x = carouselX + c * width + carouselHalfGap;
      m_art.y = carouselY + ( progress * cols - c ) + carouselHalfGap;
    }
    else
    {
      local prog = ::carouselc.transition_progress;
      if ( prog > ::carouselc.transition_swap_point )
      {
        if ( var > 0 ) c++;
        else c--;
      }

      if ( var > 0 ) prog *= -1;

      m_art.x = ( c + prog ) * width + carouselHalfGap;
      m_art.y = carouselY + r * height + carouselHalfGap;
    }
  }

  function swap( other )
  {
    m_art.swap( other.m_art );
  }

  function set_index_offset( io )
  {
    m_art.index_offset = io;
  }

  function reset_index_offset()
  {
    m_art.rawset_index_offset( m_base_io ); 
  }

  function set_alpha( alpha )
  {
    m_art.alpha = alpha; 
  }

}

local my_array = [];
for ( local i = 0; i < rows * paddedCols; i++ ) {
  my_array.push( MySlot( i ) );
}

carouselc.set_slots( my_array, carouselc.get_sel() );
carouselc.frame=fe.add_image( "frame.png", width * 2, height * 2, width, height );
carouselc.frame.preserve_aspect_ratio = true;

local title = fe.add_text(
  "[DisplayName]/[FilterName]",
  0,
  0,
  fe.layout.width * 7/8,
  fe.layout.height / 40
);
title.align = Align.Left;

carouselc.num_t = fe.add_text(
  "[ListEntry]/[ListSize]",
  fe.layout.width * 7/8,
  0,
  fe.layout.width * 1/8,
  fe.layout.height / 40
);
carouselc.num_t.align = Align.Right;

carouselc.name_t =  fe.add_text(
  "[Title]",
  0,
  fe.layout.height - carouselGap - fe.layout.height / 40,
  fe.layout.width, fe.layout.height / 40
);

carouselc.update_frame();
