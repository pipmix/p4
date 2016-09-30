//#pragma pack_matrix( row_major )

cbuffer cbPerFrame : register(b0) {
	matrix cameraScreenMatrix;
	matrix cameraMatrix;
	matrix screenMatrix;

}

cbuffer cbPerMesh : register(b1) {
	matrix worldMatrix;

}

cbuffer cbPerResize : register(b2) {
	float4 screenDim;

}


struct VS_OUT {
	float4 position : SV_POSITION;
	float4 color	: COLOR;
	float2 uv		: TEXCOORD;

};


VS_OUT main(float4 position : POSITION, float4 normal : NORMAL, float2 texcoord : TEXCOORD) {


	VS_OUT vs_out;


	matrix final; 

	float4 col = float4(0.4, 0.4, 0.4, 1.0);
	float lgtVec = float4(1.0f, 1.0f, 1.0f, 0.0f);
	float4 lgtCol = float4(0.9, 0.9, 0.9, 1.0);

	vs_out.position = mul(screenMatrix, mul(cameraMatrix, mul(worldMatrix, position)));
	vs_out.uv = texcoord;

	//vs_out.color = col + lgtCol * saturate(dot(lgtVec, (normalize(mul(worldMatrix, normal)))));

	float3 LightDirection = float3(1, 1, 1);
	float3 LightColor = float3(0.9, 0.9, 0.9);

	vs_out.color = col + lgtCol * saturate(dot(lgtVec,normalize(mul(worldMatrix, normal))));
	return vs_out;
}