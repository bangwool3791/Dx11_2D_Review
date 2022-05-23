#include "GameEngineRenderer.h"
#include "GameEngineActor.h"
#include "GameEngineLevel.h"
#include <Windows.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineCore/GameEngineVertexBuffer.h>
#include <GameEngineCore/GameEngineIndexBuffer.h>
#include <GameEngineBase/GameEngineDebug.h>   
#include <GameEngineBase/GameEngineMath.h>
#include <iostream>

GameEngineRenderer::GameEngineRenderer() 
{
}

GameEngineRenderer::~GameEngineRenderer() 
{
}


void GameEngineRenderer::Start() 
{
	GetActor()->GetLevel()->PushRenderer(this);
}

void GameEngineRenderer::Render(float _DeltaTime)
{
	GameEngineVertexBuffer* Vertex = GameEngineVertexBuffer::Find("Triangle");
	GameEngineIndexBuffer* Index = GameEngineIndexBuffer::Find("Triangle");

	static std::vector<float4> LocalPos;
	static std::vector<float4> ReverseLocalPos;

	if (!LocalPos.capacity() || !ReverseLocalPos.capacity())
	{
		LocalPos.resize(Index->Indexs.size());
		ReverseLocalPos.resize(Index->Indexs.size());

		for (size_t i = 0; i < Index->Indexs.size(); i++)
		{
			LocalPos[i] = Vertex->Vertexs[i];
			LocalPos[i] -= float4{ 0.f, 0.125f };
			ReverseLocalPos[i] = Vertex->Vertexs[i];
			ReverseLocalPos[i] -= float4{ 0.f, 0.125f };
			ReverseLocalPos[i] = float4::VectorRotationToRadianZ(ReverseLocalPos[i], GameEngineMath::PIE);
		}
	}


	std::vector<POINT> DrawVertex;
	DrawVertex.resize(Index->Indexs.size());
	std::vector<float4> CopyBuffer;
	CopyBuffer.resize(Index->Indexs.size());

	for (size_t i = 0; i < Index->Indexs.size(); i++)
	{
		LocalPos[i] = float4::VectorRotationToRadianZ(LocalPos[i], GameEngineMath::PIE2 * _DeltaTime);
		CopyBuffer[i] = LocalPos[i];
		CopyBuffer[i] *= GetActor()->GetTransform().GetScale();
		CopyBuffer[i] += GetActor()->GetTransform().GetPosition();
		DrawVertex[i] = CopyBuffer[i].GetConvertWindowPOINT();
	}

	for (size_t i = 0; i < Index->Indexs.size(); i+= 3)
	{
		Polygon(GameEngineWindow::GetHDC(), &DrawVertex[i], 3);
	}

	std::vector<POINT>().swap(DrawVertex);
	DrawVertex.clear();
	DrawVertex.resize(Index->Indexs.size());

	std::vector<float4>().swap(CopyBuffer);
	CopyBuffer.clear();
	CopyBuffer.resize(Index->Indexs.size());

	for (size_t i = 0; i < Index->Indexs.size(); i++)
	{
		ReverseLocalPos[i] = float4::VectorRotationToRadianZ(ReverseLocalPos[i], GameEngineMath::PIE2 * _DeltaTime);
		CopyBuffer[i] = ReverseLocalPos[i];
		CopyBuffer[i] *= GetActor()->GetTransform().GetScale();
		CopyBuffer[i] += GetActor()->GetTransform().GetPosition();
		DrawVertex[i] = CopyBuffer[i].GetConvertWindowPOINT();
	}

	for (size_t i = 0; i < Index->Indexs.size(); i += 3)
	{
		Polygon(GameEngineWindow::GetHDC(), &DrawVertex[i], 3);
	}
}