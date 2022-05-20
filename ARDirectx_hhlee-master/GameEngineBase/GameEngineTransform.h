#pragma once
#include "GameEngineMath.h"

// 설명 :
class GameEngineTransform
{
public:
	// constrcuter destructer
	GameEngineTransform();
	~GameEngineTransform();

	// delete Function
	GameEngineTransform(const GameEngineTransform& _Other) = delete;
	GameEngineTransform(GameEngineTransform&& _Other) noexcept = delete;
	GameEngineTransform& operator=(const GameEngineTransform& _Other) = delete;
	GameEngineTransform& operator=(GameEngineTransform&& _Other) noexcept = delete;

protected:

private:
	//부피 크기
	float4 Scale;
	//회전 360분법
	float4 Rotation;
	//위치
	float4 Position;
public :
	//여기서 인라인은 왜 붙이지?
	inline void SetScale(const float4& _Value)
	{
		Scale = _Value;
	}

	inline void SetRotation(const float4& _Value)
	{
		Rotation = _Value;
	}

	inline void SetPosition(const float4& _Value)
	{
		Position = _Value;
	}

	inline float4 GetScale()
	{
		return Scale;
	}

	inline float4 GetRotation()
	{
		return Rotation;
	}

	inline float4 GetPosition()
	{
		return Position;
	}
};

