#pragma once
#include <Windows.h>
#include <string>
#include "GameEngineMath.h"
#include "GameEngineDebug.h"
#include <functional>

// ���� :
class GameEngineWindow
{
private:
	static GameEngineWindow* Inst_;
	static HWND hWnd_;

public:
	inline static GameEngineWindow* GetInst() 
	{
		return Inst_;
	}

	static void Destroy()
	{
		if (nullptr != Inst_)
		{
			delete Inst_;
			Inst_ = nullptr;
		}
	}

public:
	void RegClass(HINSTANCE _hInst);
	void CreateGameWindow(HINSTANCE _hInst, const std::string& _Title);
	void ShowGameWindow();
	void MessageLoop(std::function<void()> _Init, std::function<void()> _Loop, std::function<void()> _End);

	void SetWindowScaleAndPosition(float4 _Pos, float4 _Scale);

	void Off();

	static inline HDC GetHDC()
	{
		return Inst_->HDC_;
	}

	static inline float4 GetScale()
	{
		return Inst_->Scale_;
	}

	static  HWND Get_hWnd() {
		return hWnd_;
	}
protected:

private:
	std::string Title_;
	bool WindowOn_;
	HINSTANCE hInst_;
	HDC HDC_;
	float4 Scale_;

	// constrcuter destructer
	GameEngineWindow();
	~GameEngineWindow();

	// delete Function
	GameEngineWindow(const GameEngineWindow& _Other) = delete;
	GameEngineWindow(GameEngineWindow&& _Other) noexcept = delete;
	GameEngineWindow& operator=(const GameEngineWindow& _Other) = delete;
	GameEngineWindow& operator=(GameEngineWindow&& _Other) noexcept = delete;

	static LRESULT CALLBACK MessageProcess(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

};

