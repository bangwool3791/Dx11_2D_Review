#pragma once
#include "GameEngineMath.h"
#include <list>

// ���� :
//Ʈ�������� ���ð� ���� ����� ������ �ִ�. 

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
	//���� ��� ������ Set
	inline void SetLocalScale(const float4& _Value)
	{
		LocalScale = _Value;
		LocalScaleMat.Scale(LocalScale);
	}

	// �ƹ��� ���Ǽ� �Լ��� ��������
	//���� ��� ȸ�� Set
	//float4�� ������ Value ���� ���ڴ� Degree�� ����ϴ� ���� ���� �ȴ�.
	void SetLocalRotation(const float4& _Value)
	{
		LocalRotation = _Value;
		//ȸ���� �׻� Degree�� ����Ѵ�.
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
	//�θ� Ʈ������
	GameEngineTransform* Parent;
	//�ڽ� Ʈ������
	//�������δ� ������ ������, �浹ü ����� �ڽ��� �ɰ� ����.
	std::list<GameEngineTransform*> Childs;

	// ���ð� ������ ���̰� ���� ������ Ȯ���� ��ƾ��մϴ�..
	// �ڴ��� ����� ũ��, ȸ��, ��ġ ���� ��ȯ �ޱ� ���� ��� ����
	float4 LocalScale;
	float4 LocalRotation;
	float4 LocalPosition;
	//���� ������, ȸ��, ��ġ
	float4 WorldScale;
	float4 WorldRotation;
	float4 WorldPosition;
	//���� ��� ũ��
	float4x4 LocalScaleMat;
	//���� ��� ��ġ
	float4x4 LocalPositionMat;
	//���� ��� ȸ��
	float4x4 LocalRotateMat;
	//���� ���
	//ũ�� * ��ġ * ȸ�� = �������
	float4x4 LocalWorldMat;
	
	float4x4 WorldWorldMat;
};
