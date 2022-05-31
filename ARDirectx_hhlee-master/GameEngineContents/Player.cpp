#include "Player.h"
#include <GameEngineCore/GEngine.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineBase/GameEngineInput.h>

Player::Player()
	:TimeAngle(0.f)
{
}

Player::Player(const float4& _Pos, float Angle)
	:TimeAngle(0.f)
	, PosAngle(Angle)
{
	GetTransform().SetLocalPosition(float4{0.f , 0.f, 0.f});
	Pos = _Pos;
	Pos.Normal2D();
}

Player::~Player()
{
}

void Player::Start()
{

	{
		//여기서 생성한 랜더러가 TitleLog 트랜스폼을 부모로 가지며,
		//랜더러 안에서 월드 변환을 진행한다.
		RendererComponent = CreateComponent<GameEngineRenderer>();
		RendererComponent->GetTransform().SetLocalScale({ 100, 100, 100 });
	}

	{
		GameEngineCamera* Camera = CreateComponent<GameEngineCamera>();
	}

	TimeAngle = 0.0f;
}

void Player::Update(float _DeltaTime)
{
	TimeAngle += _DeltaTime * 360.f;
	//Pos += float4{ _DeltaTime * 1.f, _DeltaTime * 1.f, 0.f };
	GetTransform().SetLocalMove(Pos * 3);

	if (360.f < TimeAngle)
		TimeAngle = 0.f;
}

void Player::End()
{
	int a = 0;
}