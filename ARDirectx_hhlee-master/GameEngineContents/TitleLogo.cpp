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
		//���⼭ ������ �������� TitleLog Ʈ�������� �θ�� ������,
		//������ �ȿ��� ���� ��ȯ�� �����Ѵ�.
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