// create and return a perspective matrix
//
// vfov is the vertical field of view (in the y direction)
// aspect is the aspect ratio of the viewport (width/height)
// znear is the distance to the near clip plane (znear > 0)
// zfar is the distance to the far clip plane (zfar > znear)
std::array<float, 16> mat4perspective(float vfov, float aspect, float znear, float zfar);
