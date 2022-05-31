#pragma once
#include "GameEngineMath.h"
#include <list>

// 설명 :
//트랜스폼은 로컬과 월드 행렬을 가지고 있다. 

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


public:
	//Local Area Function
	//로컬 행렬 스케일 Set
	inline void SetLocalScale(const float4& _Value)
	{
		LocalScale = _Value;
		LocalScaleMat.Scale(LocalScale);
	}

	// 아무리 편의성 함수가 많아져도
	//로컬 행렬 회전 Set
	//float4로 들어오는 Value 값의 인자는 Degree를 사용하는 각도 값이 된다.
	void SetLocalRotation(const float4& _Value)
	{
		LocalRotation = _Value;
		//회전은 항상 Degree를 사용한다.
		LocalRotateMat.RotationRadian(LocalRotation * GameEngineMath::DegreeToRadian);
	}

	inline void SetLocalPosition(const float4& _Value)
	{
		LocalPosition = _Value;
		LocalPositionMat.Position(LocalPosition);
	}

	inline void SetLocalMove(const float4& _Value)
	{
		SetLocalPosition(LocalPosition + _Value);
	}

	inline float4 GetLocalScale() const
	{
		return LocalScale;
	}
	inline float4 GetLocalRotation() const
	{
		return LocalRotation;
	}
	inline float4 GetLocalPosition() const
	{
		return LocalPosition;
	}

	inline float4x4 GetLocalWorld() const
	{
		return LocalWorldMat;
	}

	//World Function Area
	inline void SetWorldScale(const float4& _Value)
	{
		WorldScale = _Value;
		WorldWorldMat.Scale(WorldScale);
	}

	void SetWorldRotation(const float4& _Value)
	{
		WorldRotation = _Value;
		WorldWorldMat.RotationRadian(WorldRotation * GameEngineMath::DegreeToRadian);
	}

	inline void SetWorldPosition(const float4& _Value)
	{
		WorldPosition = _Value;
		WorldWorldMat.Position(WorldPosition);
	}

	inline void SetWorldMove(const float4& _Value)
	{
		SetWorldMove(WorldPosition + _Value);
	}

	inline float4 GetWorldScale() const
	{
		return WorldScale;
	}
	inline float4 GetWorldRotation() const
	{
		return WorldRotation;
	}
	inline float4 GetWorldPosition() const
	{
		return WorldPosition;
	}

	inline float4x4 GetWorldWorld() const
	{
		return WorldWorldMat;
	}

	void CalculateWorld();

	void PushChild(GameEngineTransform* _Child);

protected:

private:
	//부모 트랜스폼
	GameEngineTransform* Parent;
	//자식 트랜스폼
	//느낌으로는 액터의 랜더러, 충돌체 등등이 자식이 될것 같다.
	std::list<GameEngineTransform*> Childs;

	// 로컬과 월드의 차이가 뭐냐 개념을 확실히 잡아야합니다..
	// 코더가 행렬의 크기, 회전, 위치 값을 반환 받기 위한 멤버 변수
	float4 LocalScale;
	float4 LocalRotation;
	float4 LocalPosition;
	//월드 스케일, 회전, 위치
	float4 WorldScale;
	float4 WorldRotation;
	float4 WorldPosition;
	//로컬 행렬 크기
	float4x4 LocalScaleMat;
	//로컬 행렬 위치
	float4x4 LocalPositionMat;
	//로컬 행렬 회전
	float4x4 LocalRotateMat;
	//로컬 행렬
	//크기 * 위치 * 회전 = 로컬행렬
	float4x4 LocalWorldMat;
	
	float4x4 WorldWorldMat;
};
