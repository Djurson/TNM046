#include "Rotator.hpp"

// --- Put this before the rendering loop, but after the window is opened.
KeyRotator myKeyRotator(window);
MouseRotator myMouseRotator(window);

// --- Put this in the rendering loop
myKeyRotator.poll();
// Create a rotation matrix that depends on myKeyRotator.phi and myKeyRotator.theta
...
myMouseRotator.poll();
// Create rotation matrix that depends on myMouseRotator.phi and myMouseRotator.theta
...
