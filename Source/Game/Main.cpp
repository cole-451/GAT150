

#include "Player.h"
#include "SpaceGame.h"
#include "GamePCH.h"
#include "EnginePCH.h"
#include "Engine.h"


using namespace parabellum;


int main(int argc, char* argv[]) {
    parabellum::File::SetCurrentDirectory("Assets");

    std::cout << File::GetCurrentDirectory() << std::endl;

    auto spriterenderer = Factory::Instance().Create("MeshRenderer");
    spriterenderer->name = "kevin";

    //inits.
    getEngine().initialize();
    SDL_Init(SDL_INIT_VIDEO);
    
    //initialize sounds

    getEngine().getAudioSys().addSound("bass.wav", "bass");
    getEngine().getAudioSys().addSound("music.mp3", "music");
    getEngine().getAudioSys().addSound("Boom8.wav", "shoot");


    std::unique_ptr<SpaceGame> game = std::make_unique<SpaceGame>();


    //create vidya game
    std::unique_ptr<SpaceGame> spacegame = std::make_unique<SpaceGame>();
    
     spacegame->initialize(); 



    void* extradriverdata = nullptr;

    std::vector<vec2> stars;
    std::vector<vec2> points;

    // loading music vector
    
    std::vector<FMOD::Sound*> sounds;

    for (int i = 0; i < 100; i++) {
        stars.push_back(vec2{random::getReal() * 1280.0f, random::getReal(1024.0f) });
    }
	vec2 v(30, 40);
   

    SDL_Event e;
    bool quit = false;

    spacegame->initialize();




    FMOD::Sound* sound = nullptr;
 


    getEngine().getAudioSys().playSound("bass");
    auto texture = parabellum::Resources().Get<parabellum::Texture>("the_legend.jpg", getEngine().getRenderer());


    //MAIN LOOP
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
               
                quit = true;
            }
        }

        //update all Engine.cpp systems
        getEngine().update();

       
        

        vec2 mouse = getEngine().getInputSys().getMousePos();

        vec2 speed{ 0.1f,0.1f };
        auto i = 10;
		float length = speed.length();

        vec3 color{ 0,0,1 };
        
        getEngine().getRenderer().setColor(color.r, color.g, color.b); //switch

        //drawing

        //background drawing and updating.
        getEngine().getRenderer().setColor((uint8_t) 0, (uint8_t)0, (uint8_t)0);
        getEngine().getRenderer().clear(); // make the background black
       
       
        spacegame->Update();
        spacegame->Draw(getEngine().getRenderer());

        getEngine().getRenderer().present(); // Render the screen
    }


    
    spacegame.release();
    getEngine().GTFO();
    
    return 0;
}
