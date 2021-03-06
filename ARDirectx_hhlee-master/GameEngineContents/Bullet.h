#pragma once
#include "GameEngineCore/GameEngineActor.h"

// ???? :
class Bullet : public GameEngineActor
{
public:
	// constrcuter destructer
	Bullet();
	//Bullet(float4 _Pos);
	~Bullet();

	// delete Function
	Bullet(const Bullet& _Other) = delete;
	Bullet(Bullet&& _Other) noexcept = delete;
	Bullet& operator=(const Bullet& _Other) = delete;
	Bullet& operator=(Bullet&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

private:

	float TimeAngle;

};

