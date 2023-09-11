import {
  processLeftSidebars
} from './common/overlay-functions.js';

const friendsWindowMatcher = ['riends'];

const run = () => {
  console.log(`Opened ${window.name}.`);

  processLeftSidebars(friendsWindowMatcher);
};
run();
