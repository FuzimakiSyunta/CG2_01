#include<Windows.h>
#include<cstdint>
#include<string>

//ウィンドウプロシージャ
LRESULT CALLBACK Windowproc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
//メッセージに応じてゲーム固有の処理を行う
	switch (msg) {
		//ウィンドウが破壊された
	case WM_DESTROY:
		//OSに対して、アプリの終了を伝える
		PostQuitMessage(0);
		return 0;
	}
	//標準のメッセージ処理を行う
	return DefWindowProc(hwnd, msg, wparam, lparam);
}
    //Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){
	WNDCLASS wc{};
	//ウィンドウプロシージャ
	wc.lpfnWndProc = Windowproc;
	//ウィンドウクラス名
	wc.lpszClassName = L"CG2WindowClass";
	//インスタンスハンドル
	wc.hInstance = GetModuleHandle(nullptr);
	//カーソル
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);


	//ウィンドウクラスを登録する
	RegisterClass(&wc);

	//クライアント領域のサイズ
	const int32_t kClienWidth = 1280;
	const int32_t kClientHeight = 720;

	//ウィンドウサイズを表す構造体にクライアント領域を入れる
	RECT wrc = {0, 0, kClienWidth, kClientHeight};

	//クライアント領域を元に実際のサイズにwrcを変更してもらう
	AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);

	//ウィンドウの生成
	HWND hwnd = CreateWindow(
	    wc.lpszClassName,//利用するクラス名
		L"CG2",//タイトルバーの文字
		WS_OVERLAPPEDWINDOW,//表示X座標(Windowsに任せる)
		CW_USEDEFAULT, CW_USEDEFAULT,//表示Y座標(WindowsOSに任せる)
	    wrc.right - wrc.left,//ウィンドウ横幅
		wrc.bottom - wrc.top, //ウィンドウ縦幅
		nullptr, //親ウィンドウハンドル
		nullptr, //メニューハンドル
		wc.hInstance, //インスタンス
		nullptr);//オプション
	//ウィンドウを表示する
	ShowWindow(hwnd, SW_SHOW);

	MSG msg{};
	//ウィンドウの×ボタンが押されるまでループ
	while (msg.message!=WM_QUIT) {
		//Windowにメッセージが来てたら最優先で処理させる
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		} else {
			//ゲームの処理
		}
	}

 ////出力ウィンドウへの文字出力
 //OutputDebugStringA("Hello,DirectX!\n");

return 0;
}