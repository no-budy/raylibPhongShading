#include <raylib.h>
#include <math.h>

int main(){

    InitWindow(1280,720, "Model Test");


    //Load our model and shader
    Model model = LoadModel("./teapot.obj");
    Shader shader = LoadShader(0, TextFormat("./light.fs", 330));

    //assign the shader to the model
    model.materials[0].shader = shader;

//    Texture2D text = LoadTexture("")

    //Setup the camer position, look vector, upvector, projection type, and fov
    Camera cam = {0};
    cam.position = (Vector3){3.5f, 3.5f, 3.5f};
    cam.target = (Vector3){0.0f,0.0f,0.0f};
    cam.up = (Vector3){0.0f,1.0f,0.0f};
    cam.fovy = 90.0f;
    cam.projection = CAMERA_PERSPECTIVE;

    Vector3 pos = {0.0f, 0.0f, 0.0f};
    //BoundingBox bounds = GetMeshBoundingBox(model.meshes[0]);



    //Limit FPS
    SetTargetFPS(60);


    //If not ESC or x
    while(!WindowShouldClose()){

    UpdateCamera(&cam, CAMERA_THIRD_PERSON);

        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode3D(cam);
                DrawModel(model, pos, 1.0f, GRAY);
                DrawGrid(20, 10.0f);
            EndMode3D();
            DrawText("Loading obj file", 10, GetScreenHeight()-20, 35, DARKGRAY);
        EndDrawing();
    }

// UnloadTexture(tex);
//Unload Model and then close up
    UnloadModel(model);
    CloseWindow();
}
