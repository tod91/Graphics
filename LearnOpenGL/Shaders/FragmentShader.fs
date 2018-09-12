#version 330 core
out vec4 FragColor;

//in vec3 ourColor;
in vec2 v_TexCoord;

// texture samplers
uniform sampler2D containerTex;
uniform sampler2D smileTex;

void main()
{
    // linearly interpolate between both textures (80% container, 20% awesomeface)
    FragColor = mix(texture(smileTex, v_TexCoord), texture(containerTex, v_TexCoord), 0.8);
    //FragColor = texture(containerTex, v_TexCoord);
}
