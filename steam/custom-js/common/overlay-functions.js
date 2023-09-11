const SCREEN_WIDTH = 1920;
const SCREEN_HEIGHT = 1080;
const FOOTER_HEIGHT = 64;
const VIEWPORT_HEIGHT = SCREEN_HEIGHT - FOOTER_HEIGHT;

const SIDEBAR_WIDTH = SCREEN_WIDTH / 3.75;
const CENTER_WIDTH = SCREEN_WIDTH - SIDEBAR_WIDTH * 2;

const LEFT_X = 0;
const CENTER_X = SIDEBAR_WIDTH;
const RIGHT_X = SCREEN_WIDTH - SIDEBAR_WIDTH;

const processWindow = (windowName, width, height = VIEWPORT_HEIGHT, x) => {  
  if (window.name.includes(windowName)) {
    SteamClient.Window.ResizeTo(width, height, 1);
    SteamClient.Window.MoveTo(x, 0);
  }
}

const processWindows = (windowNames, width, height, x) => {
  windowNames.forEach((windowName) => {
    processWindow(windowName, width, height, x);
  });
}

export const processLeftSidebars = (windowNames) => {
  processWindows(windowNames, SIDEBAR_WIDTH, SCREEN_HEIGHT, LEFT_X);
}
export const processCenterWindows = (windowNames) => {
  processWindows(windowNames, CENTER_WIDTH, VIEWPORT_HEIGHT, CENTER_X);
}
export const processRightSidebars = (windowNames) => {
  processWindows(windowNames, SIDEBAR_WIDTH, SCREEN_HEIGHT, RIGHT_X);  
}
