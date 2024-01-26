#include <Novice.h>
#include "Player.h"
#include "Enemy.h"

const char kWindowTitle[] = "LC1B_04_オオタケ_アオイ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	int startHandle;
	int clearHandle;
	int gameoverHandle;
	startHandle = Novice::LoadTexture("./images/GAMESTART.png");
	clearHandle = Novice::LoadTexture("./images/GAMECLEAR.png");
	gameoverHandle = Novice::LoadTexture("./images/GAMEOVER.png");
		Player* player = new Player;

		Enemy* enemy = new Enemy;

		enum Scene
		{
			title,
			game,
			clear,
			gameover,
		};
		Scene scene = title;
	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		switch (scene)
		{
		case title:
			if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0)
			{
				scene = game;
			}
			break;
		case game:
			player->Update(keys, preKeys);
			enemy->Update(player);
			if (player->GetHP() == 0)
			{
				scene = gameover;
			}
			if (enemy->GetisAlive() == FALSE)
			{
				scene = clear;
			}
			break;
		case clear:
			if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0)
			{
				scene = title;
				player->resetPlayer();
				player->Bullet_.resetBullet();
				enemy->resetEnemy();
			}
			break;
		case gameover:
			if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0)
			{
				scene = game;
				player->resetPlayer();
				player->Bullet_.resetBullet();
				enemy->resetEnemy();
			}
			break;
		};
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		switch (scene)
		{
		case title:
			Novice::DrawSprite(0, 0, startHandle, 1, 1, 0.0f, WHITE);
			break;
		case game:
			player->Draw();
			player->Bullet_.Draw();
			enemy->Draw();
			break;
		case clear:
			Novice::DrawSprite(0, 0, clearHandle, 1, 1, 0.0f, WHITE);
			break;
		case gameover:
			Novice::DrawSprite(0, 0, gameoverHandle, 1, 1, 0.0f, WHITE);
			break;

		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
