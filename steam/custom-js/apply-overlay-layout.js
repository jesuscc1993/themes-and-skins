import {
  centerWindows,
  processLeftSidebars,
  processMiddleColumns,
  processRightSidebars,
} from './common/overlay-functions.js';

const leftSidebars = [
  'GameOverview'
];

const middleColumns = [
  'GameNotes',
  'OverlayBrowser_Browser',
  'OverlayBrowser_Discussions',
  'OverlayBrowser_Guides',
  'OverlayBrowser_Workshop',
  'ScreenshotManager',
];

const rightSidebars = [
  'Achievements'
];

const centeredWindows = [
  'ControllerConfigurator',
  'OverlayTimer',
  'Settings'
];

const run = () => {
  console.log(`Opened ${window.name}.`);

  processLeftSidebars(leftSidebars);
  processMiddleColumns(middleColumns);
  processRightSidebars(rightSidebars);

  centerWindows(centeredWindows);
};
run();
