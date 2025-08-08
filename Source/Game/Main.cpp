#include <iostream>
#include <vector>
#include <memory>

#include "Math/Math.h"
#include "Core/Random.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Math/Vector2.h"
#include "Core/Time.h"
#include "Framework/Actor.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
#include "Math/Vector3.h"
#include "Math/Transform.h"
#include "Framework/Scene.h"
#include "Engine.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include "Core/File.h"
#include "Renderer/Texture.h"
#include "Resources/ResourceManager.h"

#include "Game/FileGame.h"




int main(int argc, char* argv[]) {

    //initialize engine 
	whermst::GetEngine().Initialize();

	
    
    //initialize game
	std::unique_ptr<whermst::Game> game = std::make_unique<FileGame>();
	game->Initialize();
	

   //initialize font
	

    //initialize Text
    

    //initialize image
	

    SDL_Event e;
    bool quit = false;


    

		
    
  
    //MAIN LOOP
    while (!quit) {

        //update engine		
     
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
            whermst::GetEngine().GetInput().HandleEvent(e);
        }

        whermst::GetEngine().Update();

        if (whermst::GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_ESCAPE)) {
            quit = true;
        }
      
      
        //draw
        
        

        

        


		game->Draw(whermst::GetEngine().GetRenderer());

       whermst::GetEngine().GetRenderer().Present(); // Render the screen
    }
	 // Shutdown the game
	 // Release the game object
	whermst::GetEngine().Shutdown(); // Shutdown the engine

    return 0;
}
