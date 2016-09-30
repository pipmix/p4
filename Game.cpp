#include "Game.h"

Game::Game(){}


void Game::Load(){

	gCam.Create();
	

	md01.AssignResources(DT_WALL01, DV_BASICLIGHTING, DP_BASICLIGHTING);
	md01.LoadMesh(L"plane");

	md02.AssignResources(DT_WALL01, DV_BASICLIGHTING, DP_BASICLIGHTING);
	md02.LoadMesh(L"b_sphere");

	md03.AssignResources(DT_WALL01, DV_BASICLIGHTING, DP_BASICLIGHTING);
	md03.LoadMesh(L"b_sphere");

	md03.MoveTo(XMFLOAT3{ 0.0f, 0.0f, 4.0f });



}

void Game::Update(double deltaTime) {

	

	gCam.Update(deltaTime);

	md02.m_position.x += 0.02f;
	if (md02.m_position.x > 4.0f)md02.m_position.x = -4.0f;

	md03.m_position.z += 0.02f;
	if (md03.m_position.z > 4.0f)md03.m_position.z = -4.0f;

}


void Game::Draw() {

	CB_mmm perFrame;
	perFrame.mat1 = gCam.GetCameraScreenMatrix();
	perFrame.mat2 = gCam.GetCameraMatrix();
	perFrame.mat3 = gCam.GetScreenMatrix();

	gContext->UpdateSubresource(gcbPerFrame.Get(), 0, 0, &perFrame, 0, 0);



	//geo01.Draw();

	md01.Draw();
	md02.Draw();
	md03.Draw();



}

