struct Material {
	float32_t4 color;
};
ConstantBuffer<Material> gMaterial : register(b0);

struct PixcelShaderOutput {
	float32_t4 color : SV_TARGET0;
};

PixcelShaderOutput main() { 
	PixcelShaderOutput output;
	output.color = gMaterial.color;
	return output;
}