#include <GameEngineCore/GameEngineCore.h>

// Resources Header
#include "GameEngineVertexBuffer.h"
#include "GameEngineIndexBuffer.h"

void GameEngineCore::EngineResourcesInitialize()
{
	std::vector<float4> Vertex;
	Vertex.push_back(float4{ -0.5f, 0.5f});
	Vertex.push_back(float4{ 0.5f, 0.5f });
	Vertex.push_back(float4{ 0.5f, -0.5f });
	Vertex.push_back(float4{ -0.5f, -0.5f });

	GameEngineVertexBuffer::Create("Rect", Vertex);

	std::vector<int> Index;

	Index.resize(6);
	Index[0] = 0;
	Index[1] = 1;
	Index[2] = 2;

	Index[3] = 0;
	Index[4] = 2;
	Index[5] = 3;

	GameEngineIndexBuffer::Create("Rect", Index);

	Vertex.clear();
	std::vector<float4>().swap(Vertex);
	Vertex.push_back(float4{ 0.f, -0.5f });
	Vertex.push_back(float4{ 0.5f, 0.5f });
	Vertex.push_back(float4{ -0.5f, 0.5f });

	GameEngineVertexBuffer::Create("Triangle", Vertex);

	Index.clear();
	std::vector<int>().swap(Index);
	Index.resize(3);
	Index[0] = 0;
	Index[1] = 1;
	Index[2] = 2;

	GameEngineIndexBuffer::Create("Triangle", Index);
}
void GameEngineCore::EngineResourcesDestroy()
{
	GameEngineVertexBuffer::ResourcesDestroy();
	GameEngineIndexBuffer::ResourcesDestroy();
}
