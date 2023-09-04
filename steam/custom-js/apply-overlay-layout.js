const leftSidebars = ['riends', 'GameOverview'];

const centerWindows = [
  // "ControllerConfigurator",
  'GameNotes',
  'OverlayBrowser_Browser',
  'OverlayBrowser_Discussions',
  'OverlayBrowser_Guides',
  'OverlayBrowser_Workshop',
  // "Settings"
];

const rightSidebars = ['Achievements'];

const run = () => {
  console.log(`Opened ${window.name}.`);

  processLeftSidebars(leftSidebars);
  processCenterWindows(centerWindows);
  processRightSidebars(rightSidebars);
};
run();
