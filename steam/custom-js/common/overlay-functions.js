const SCREEN_WIDTH = 1920;
const SCREEN_HEIGHT = 1080;
const FOOTER_HEIGHT = 64;
const VIEWPORT_HEIGHT = SCREEN_HEIGHT - FOOTER_HEIGHT;

/* start: columns */
const SIDEBAR_WIDTH = SCREEN_WIDTH / 3.75;
const CENTER_WIDTH = SCREEN_WIDTH - SIDEBAR_WIDTH * 2;

const LEFT_X = 0;
const CENTER_X = SIDEBAR_WIDTH;
const RIGHT_X = SCREEN_WIDTH - SIDEBAR_WIDTH;
/* end: columns */

const resizeWindow = (width, height, x = 0, y = 0) => {
  if (width !== undefined && height !== undefined) {
    SteamClient.Window.ResizeTo(width, height, 1);
    console.log(`Resized window "${window.name}" to ${width}x${height}.`);
  }
};

const moveWindow = (x, y) => {
  if (x !== undefined && y !== undefined) {
    SteamClient.Window.MoveTo(x, y);
    console.log(`Moved window "${window.name}" to (${x}, ${y}).`);
  }
};

const centerWindow = (windowName) => {
  if (window.name.includes(windowName)) {
    const x = (SCREEN_WIDTH - window.innerWidth) / 2;
    const y = (SCREEN_HEIGHT - window.innerHeight) / 2;

    console.log(`Centering window "${window.name}"...`);
    moveWindow(x, y);
  }
};

const processWindows = (windowNames, width, height, x, y) => {
  windowNames.forEach((windowName) => {
    if (window.name.includes(windowName)) {
      resizeWindow(width, height);
      moveWindow(x, y);
    }
  });
};

export const centerWindows = (windowNames) => {
  windowNames.forEach((windowName) => {
    if (window.name.includes(windowName)) {
      centerWindow(windowName);
    }
  });
};

export const processLeftSidebars = (windowNames) => {
  processWindows(windowNames, SIDEBAR_WIDTH, SCREEN_HEIGHT, LEFT_X);
};
export const processCenterColumns = (windowNames) => {
  processWindows(windowNames, CENTER_WIDTH, VIEWPORT_HEIGHT, CENTER_X);
};
export const processRightSidebars = (windowNames) => {
  processWindows(windowNames, SIDEBAR_WIDTH, SCREEN_HEIGHT, RIGHT_X);
};
