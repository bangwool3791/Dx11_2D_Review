#include "TitleLogo.h"
#include <GameEngineCore/GEngine.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineBase/GameEngineInput.h>

TitleLogo::TitleLogo() 
{
}

TitleLogo::~TitleLogo() 
{
}

void TitleLogo::Start() 
{
	
	// GetTransform().SetLocalScale({ 100, 100, 100 });
	GetTransform().SetLocalPosition({ 300, 300, 100 });


	{
		//여기서 생성한 랜더러가 TitleLog 트랜스폼을 부모로 가지며,
		//랜더러 안에서 월드 변환을 진행한다.
		RendererComponent = CreateComponent<GameEngineRenderer>();
		RendererComponent->GetTransform().SetLocalScale({ 100, 100, 100 });
		RendererComponent->GetTransform().SetLocalPosition({ 100, 100, 100 });
	}

	{
		GameEngineCamera* Camera = CreateComponent<GameEngineCamera>();
	}

	TimeAngle = 0.0f;
}

void TitleLogo::Update(float _DeltaTime) 
{
	TimeAngle += _DeltaTime * 90.0f;

	static float4 Pos = float4{ _DeltaTime , 0, 0, 0};
	Pos += float4{ _DeltaTime , 0, 0, 0 };
	GetTransform().SetLocalMove(Pos);
	//GetTransform().SetLocalRotation({ 0.0f , 0.0f, TimeAngle });
	RendererComponent->GetTransform().SetLocalRotation({ TimeAngle , TimeAngle, TimeAngle });
}

void TitleLogo::End() 
{
	int a = 0;
}