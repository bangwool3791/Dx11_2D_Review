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

	//Create Star

	Vertex.clear();
	std::vector<float4>().swap(Vertex);
	Vertex.resize(6);
	//정삼각형 높이 0.433 * 2

	//정방향 삼각형
	Vertex[0] = float4{0.f, -0.433f - 0.125};
	Vertex[1] = float4{ 0.5f, 0.433f - 0.125 };
	Vertex[2]  = float4{ -0.5f, 0.433f - 0.125 };
	//역방향 삼각형
	Vertex[3] = float4{ 0.f, 0.433f + 0.125 };
	Vertex[4] = float4{ 0.5f, -0.433f + 0.125 };
	Vertex[5] = float4{ -0.5f, -0.433f + 0.125 };

	GameEngineVertexBuffer::Create("Hexagram", Vertex);

	Index.clear();
	std::vector<int>().swap(Index);
	Index.resize(6);
	Index[0] = 0;
	Index[1] = 1;
	Index[2] = 2;
	Index[3] = 3;
	Index[4] = 4;
	Index[5] = 5;
	GameEngineIndexBuffer::Create("Hexagram", Index);


}
void GameEngineCore::EngineResourcesDestroy()
{
	GameEngineVertexBuffer::ResourcesDestroy();
	GameEngineIndexBuffer::ResourcesDestroy();
}
