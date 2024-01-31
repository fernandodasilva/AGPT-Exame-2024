//o que � necess�rio ter na engine
//
//- ter uma classe que represente um n�vel(Level) (possivelmente com um std::vector<gameobject>
//	-ter uma classe que represente um gameobject / Actor
//	- Um Pawn que seja Pawn : Engine::gameobject
//	- ter a janela
//	- Ter o conceito de Animation / TileMap / SpriteSheet
//
//
//	O que vai ter no Game
//	Level : Engine::Level
//
//
//	Ship ship = new Spaceship(...);
//
//level.add(ship);
//level.add(objeto);


/*
A FAZER NA GAME ENGINE :
-Ponto de entrada � Entry Point(Projeto Game->Game.cpp ? )
- Application Layer
- Window->Window.h / .cpp(n�o consigo fazer o singleton da janela)
- Input manager(eu meio que tenho isso no InputManager.h / .cpp)
- Event handler
- Renderer (preso em n�o consigo fazer o singleton)
- Usar apenas OpenGL
- Debug � SDL_Log cuida disso, n�o � necess�rio agora.
- Memory System � usando destrutores em tudo o que � necess�rio � o bastante?
- F�sica � o projeto tem que usar Box2D
- Build system � sistema de convers�o � n�o vai usar
*/

//reposit�rio no GitHub criado, mas aparentemente n�o funciona
//help, como eu coloco isso no GitHub?!



//int main(int argc, char** argv)
//{
//    GameEngine engine;
//
//    engine.init("Xennon Clone!!!", 640, 480);
//
//    //Level level = new Level();
//
//    //engine.SetMainLevel(Level);
//
//    //Spaceship s = new Spaceship();
//
//    //level.addActor(s);
//    //level.addActor(enemy1);
//    //level.addActor(enemy2);
//
//
//    engine.start();
//
//    return 0;
//}