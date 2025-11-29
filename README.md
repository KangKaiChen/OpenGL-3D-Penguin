# OpenGL-3D-Penguin

OpenGL 和 GLUT (OpenGL Utility Toolkit) 函式庫來創建一個 3D 動態場景 的應用程式。


載入並渲染一個 3D 模型 (SMF 檔案格式)，這裡是一個 橡皮鴨 (rubber_duck.smf) 的模型。

建立一個由基本幾何體 (如方塊和球體) 組成的 3D 企鵝模型，並讓它具備簡單的動畫功能（走路、揮手、張嘴）。

設置光源和材質，讓 3D 物體能夠被著色並產生立體感。
GLUT 提供了快速繪製預定義形狀的實心 (Solid) 或線框 (Wire) 函式，您用於構建您的機器人模型：
提供使用者互動功能，允許使用者透過鍵盤和滑鼠來控制視角、模型動作和燈光效果。

2.(作業環境)
	作業環境:win11 64bit
	編譯器:Visual Studio 2022
  
3.(作業指定功能)
     建立一個3D平台:
	已完成建立一個平面,將企鵝和鴨子放在上面
	已完成調整固定視角,可以方便看到平面上放的物體
	已完成將平台顏色設置成墨綠色
     製作3D企鵝:
	已完成企鵝的外型須包含三種表現方式：線框(wireframe)、固體(solid)、有線框的固體(solid w/ outlines)
	已完成企鵝的構造包含：頭、眼、喙、身體、雙翅、前翅、雙腿、蹼足
	已完成利用鍵盤，可以控制企鵝，包含：嘴部開合、脖子旋轉、蹼足及前翅前後擺動、雙腳及雙翅可旋轉、外型的表現方式改變
	已完成企鵝可以自由在平面上移動位置及旋轉
     放置3D黃色小鴨:
	已完成load小鴨模型
     場景光源設定:
	已完成環境光：場景定點光源，固定對整個場景打光
	已完成聚光燈：從企鵝的正上方往下照，且隨著企鵝移動
	已完成利用鍵盤，可以控制聚光燈的顏色(紅、藍、綠等)及方向(類似手電筒)，且當企鵝移動時，聚光燈的方向維持不變(即不會因為企鵝而重置)

4.(敘述如何操作我的作業功能)
	大寫'W'按鍵可控制企鵝的整體旋轉
	小寫'w'按鍵可控制企鵝頭部的旋轉
	小寫'e'按鍵可控制企鵝嘴巴的閉合
	小寫'q'按鍵可使企鵝朝旋轉的面向進行移動
	小寫'i'按鍵可使企鵝在(wireframe,solid,solid w/outlines)三種呈現模式做變換
	小寫'r'按鍵可控制打在企鵝上的聚光燈顏色(紅色)
	小寫'g'按鍵可控制打在企鵝上的聚光燈顏色(綠色)
	小寫'b'按鍵可控制打在企鵝上的聚光燈顏色(藍色)
	小寫'n'按鍵可控制打在企鵝上的聚光燈方向(正向移動)
	小寫'm'按鍵可控制打在企鵝上的聚光燈方向(反向移動)
	小寫'z'按鍵可使所有動作進行reset動作
  
5.(參考網址)
	https://blog.csdn.net/dcrmg/article/details/53121938(光源參考)
	https://learnopengl-cn.readthedocs.io/zh/latest/02%20Lighting/02%20Basic%20Lighting/(光源參考)
	https://www.cnblogs.com/octoptuslian/p/6872726.html (光源參考)
	https://blog.csdn.net/catoldcui/article/details/12689165 (企鵝外型參考)
	https://blog.csdn.net/dcrmg/article/details/53106457 (3D視角參考)
	https://www.twblogs.net/a/5b876d232b71775d1cd71367 (opengl 各種形狀體參考)
6.(Bonus)

	設置移動公式讓企鵝可以在當下已旋轉角度並針對相關軸做內積計算出目前移動的方向
	利用各式不同形狀體讓企鵝外表呈現上更加美化
	設置reset鍵可讓所有動作回到初始點
	設置Mouse可讓視角隨意滑動

  <img width="928" height="684" alt="image" src="https://github.com/user-attachments/assets/b6d12875-1ee0-452e-be7b-28ad0c673281" />
