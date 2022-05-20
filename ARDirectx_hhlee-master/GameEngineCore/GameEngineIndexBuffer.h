#pragma once
#include "GameEngineRes.h"
#include <GameEngineBase/GameEngineString.h>
#include <GameEngineBase/GameEngineMath.h>
#include <vector>
#include <map>
#include <list>

class GameEngineIndexBuffer : public GameEngineRes< GameEngineIndexBuffer>
{
	friend GameEngineRes<GameEngineIndexBuffer>;

public :
	static GameEngineIndexBuffer* CreateRes(const std::vector<int>& _Indexs, const std::string& _Name = ""); 
	static void	Create(const std::string& _Name, const std::vector<int>& _Indexs);
	static void	Create(const std::vector<int>& _Indexs);
private:
	// constrcuter destructer
	GameEngineIndexBuffer() {};
	~GameEngineIndexBuffer() {};

	// delete Function
	GameEngineIndexBuffer(const GameEngineIndexBuffer& _Other) = delete;
	GameEngineIndexBuffer(GameEngineIndexBuffer&& _Other) noexcept = delete;
	GameEngineIndexBuffer& operator=(const GameEngineIndexBuffer& _Other) = delete;
	GameEngineIndexBuffer& operator=(GameEngineIndexBuffer&& _Other) noexcept = delete;
public :
	std::vector<int> Indexs;
};

