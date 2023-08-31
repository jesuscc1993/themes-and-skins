const SCREEN_WIDTH = 1920;
const SCREEN_HEIGHT = 1080;
const FOOTER_HEIGHT = 64;
const VIEWPORT_HEIGHT = SCREEN_HEIGHT - FOOTER_HEIGHT;

const SIDEBAR_WIDTH = SCREEN_WIDTH / 5;
const CENTER_WIDTH = SCREEN_WIDTH - SIDEBAR_WIDTH * 2;

const LEFT_X = 0;
const CENTER_X = SIDEBAR_WIDTH;
const RIGHT_X = SCREEN_WIDTH - SIDEBAR_WIDTH;

const processWindow = (windowName, width, x) => {
  if (window.name.includes(windowName)) {
    SteamClient.Window.ResizeTo(width, VIEWPORT_HEIGHT, 1);
    SteamClient.Window.MoveTo(x, 0);
  }
}

// left
processWindow("GameOverview", SIDEBAR_WIDTH, LEFT_X);
// center
processWindow("OverlayBrowser_Discussions", CENTER_WIDTH, CENTER_X);
processWindow("OverlayBrowser_Guides", CENTER_WIDTH, CENTER_X);
// right
processWindow("Achievements", SIDEBAR_WIDTH, RIGHT_X);
