#include "Particle.hlsli"

struct Material {
	float32_t4 color;
	int32_t enableLighting;
};

ConstantBuffer<Material> gMaterial : register(b0);
struct PixcelShaderOutput {
	float32_t4 color : SV_TARGET0;
};

Texture2D<float32_t4>gTexture : register(t0);
SamplerState gSampler : register(s0);


PixcelShaderOutput main(VertexShaderOutput input) {
	float32_t4 textureColor = gTexture.Sample(gSampler, input.texcoord);
	PixcelShaderOutput output;
	output.color = gMaterial.color * textureColor;
	return output;
}
