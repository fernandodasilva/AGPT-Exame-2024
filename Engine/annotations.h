//o que é necessário ter na engine
//
//- ter uma classe que represente um nível(Level) (possivelmente com um std::vector<gameobject>
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
-Ponto de entrada – Entry Point(Projeto Game->Game.cpp ? )
- Application Layer
- Window->Window.h / .cpp(não consigo fazer o singleton da janela)
- Input manager(eu meio que tenho isso no InputManager.h / .cpp)
- Event handler
- Renderer (preso em não consigo fazer o singleton)
- Usar apenas OpenGL
- Debug – SDL_Log cuida disso, não é necessário agora.
- Memory System – usando destrutores em tudo o que é necessário é o bastante?
- Física – o projeto tem que usar Box2D
- Build system – sistema de conversão – não vai usar
*/

//repositório no GitHub criado, mas aparentemente não funciona
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