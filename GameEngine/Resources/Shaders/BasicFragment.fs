#version 330

in vec2 texCoord0;
out vec4 fragColor;

uniform sampler2D sampler;

void main()
{
    fragColor = texture(sampler, texCoord0.xy);
}
