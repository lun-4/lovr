#version 460
#extension GL_EXT_multiview : require

layout(constant_id = 1000) const bool useGlobalColor = true;

layout(location = 0) in vec4 inGlobalColor;
layout(location = 1) in vec2 inUV;

layout(location = 0) out vec4 outColor;

struct Camera {
  mat4 view[6];
  mat4 projection[6];
  mat4 viewProjection[6];
  mat4 inverseViewProjection[6];
};

layout(set = 0, binding = 0) uniform CameraBuffer { Camera camera; };

void main() {
  // does this need to be per-fragment or can it be per-vertex?
  vec3 direction = normalize((camera.inverseViewProjection[gl_ViewIndex] * vec4(inUV, 1., 0.)).xyz);
  // textureCube(skybox, direction);

  outColor = vec4(1.);

  if (useGlobalColor) {
    outColor *= inGlobalColor;
  }
}
