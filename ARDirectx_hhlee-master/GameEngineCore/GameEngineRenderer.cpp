#include "GameEngineRenderer.h"
#include "GameEngineActor.h"
#include "GameEngineLevel.h"
#include <Windows.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineCore/GameEngineVertexBuffer.h>
#include <GameEngineCore/GameEngineIndexBuffer.h>
#include <GameEngineBase/GameEngineDebug.h>                                                                      
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
	GameEngineVertexBuffer* Vertex = GameEngineVertexBuffer::Find("Rect");
	GameEngineIndexBuffer* Index = GameEngineIndexBuffer::Find("Rect");
	
	std::vector<POINT> DrawVertex;
	DrawVertex.resize(Index->Indexs.size());
	std::vector<float4> CopyBuffer;
	CopyBuffer.resize(Index->Indexs.size());

	for (size_t i = 0; i < Index->Indexs.size(); i++)
	{
		GetActor()->GetNameCopy();
		CopyBuffer[i] = Vertex->Vertexs[Index->Indexs[i]];
		CopyBuffer[i] *= GetActor()->GetTransform().GetScale();
		CopyBuffer[i] += GetActor()->GetTransform().GetPosition();
		DrawVertex[i] = CopyBuffer[i].GetConvertWindowPOINT();
	}

	for (size_t i = 0; i < Index->Indexs.size(); i+= 3)
	{
		Polygon(GameEngineWindow::GetHDC(), &DrawVertex[i], 3);
	}
}