// Basic Texture Shader

#type vertex
#version 450 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec4 a_Color;

uniform mat4 u_ViewProjection;
uniform mat4 u_Transform;

struct VertexOutput {
	vec3 posW;
};

layout(location = 0) out VertexOutput Output;

void main()
{
	vec4 posH = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);

	Output.posW = posH.xyz;
	gl_Position = posH;
}

#type fragment
#version 450 core

struct VertexOutput {
	vec3 posW;
};

layout(location = 0) in VertexOutput Input;
layout(location = 0) out vec4 color;

uniform vec4 u_Color;

void main()
{
	vec4 texColor = u_Color;
	color = texColor;
}
