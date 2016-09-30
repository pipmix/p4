Texture2D Texture : register(t0);
SamplerState ss : register(s0);




float4 main(float4 position : SV_POSITION, float4 color : NORMAL, float2 texcoord : TEXCOORD) : SV_TARGET{

	//float4 temp = color;
	//temp.w = 1;

	return color * Texture.Sample(ss, texcoord);

}

