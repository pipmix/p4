#pragma once
#include "Headers.h"
#include "Timer.h"
#include "Data.h"
#include "Camera.h"
#include "Input.h"

#include "Model.h"

extern ComPtr<ID3D11Device>				gDevice;
extern ComPtr<ID3D11DeviceContext>		gContext;
extern ComPtr<ID3D11DeviceContext>		gDContext;
extern HWND								ghWnd;
extern ComPtr<ID3D11Buffer>				gcbPerMesh;
extern ComPtr<ID3D11Buffer>				gcbPerFrame;
extern Camera gCam;
extern Input gInput;

class Dx;

class Game {
public:

			Game();
	void	Load();
	void	Update(double deltaTime);
	void	Draw();




	Model md01;
	Model md02;
	Model md03;

};