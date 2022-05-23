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

//가독성, 유지보수 떨어지는 코드
void GameEngineRenderer::Render(float _DeltaTime)
{
	GameEngineVertexBuffer* Vertex = GameEngineVertexBuffer::Find("Hexagram");
	GameEngineIndexBuffer* Index = GameEngineIndexBuffer::Find("Hexagram");

	std::vector<POINT> DrawVertex;
	DrawVertex.resize(Index->Indexs.size());
	std::vector<float4> CopyBuffer;
	CopyBuffer.resize(Index->Indexs.size());

	static float fAngle = 0.f;
	fAngle += _DeltaTime;

	for (size_t i = 0; i < Index->Indexs.size(); i++)
	{
		CopyBuffer[i] =  Vertex->Vertexs[Index->Indexs[i]];
		CopyBuffer[i] *= GetActor()->GetTransform().GetScale();
		CopyBuffer[i] = float4::VectorRotationToRadianZ(CopyBuffer[i], fAngle);
		CopyBuffer[i] += GetActor()->GetTransform().GetPosition();
		DrawVertex[i] = CopyBuffer[i].GetConvertWindowPOINT();
	}

	for (size_t i = 0; i < Index->Indexs.size(); i+= 3)
	{
		Polygon(GameEngineWindow::GetHDC(), &DrawVertex[i], 3);
	}

}