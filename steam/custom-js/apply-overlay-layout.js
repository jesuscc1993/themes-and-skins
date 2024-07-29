import {
  processCenterColumns,
  processLeftSidebars,
  processRightSidebars,
  centerWindows,
} from './common/overlay-functions.js';

const leftSidebars = ['GameOverview'];

const centerColumns = [
  'GameNotes',
  'OverlayBrowser_Browser',
  'OverlayBrowser_Discussions',
  'OverlayBrowser_Guides',
  'OverlayBrowser_Workshop',
];

const rightSidebars = ['Achievements'];

const centeredWindows = ['ControllerConfigurator', 'OverlayTimer', 'Settings'];

const run = () => {
  console.log(`Opened ${window.name}.`);

  processLeftSidebars(leftSidebars);
  processCenterColumns(centerColumns);
  processRightSidebars(rightSidebars);

  centerWindows(centeredWindows);
};
run();
