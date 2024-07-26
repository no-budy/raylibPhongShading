#include <raylib.h>


int main(){

    InitWindow(1280,720, "Model Test");

    Model model = LoadModel("./teapot.obj");

//    Texture2D text = LoadTexture("")

    Camera cam = {0};
    cam.position = (Vector3){3.5f, 3.5f, 3.5f};
    cam.target = (Vector3){0.0f,0.0f,0.0f};
    cam.up = (Vector3){0.0f,1.0f,0.0f};
    cam.fovy = 90.0f;
    cam.projection = CAMERA_PERSPECTIVE;

    Vector3 pos = {0.0f, 0.0f, 0.0f};
    BoundingBox bounds = GetMeshBoundingBox(model.meshes[0]);

    SetTargetFPS(60);

    while(!WindowShouldClose()){

        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(cam);
        DrawModel(model, pos, 1.0f, GRAY);
        DrawGrid(20, 10.0f);
        EndMode3D();
        DrawText("Loading obj file", 10, GetScreenHeight()-25, 35, DARKGRAY);
        EndDrawing();

    }
// UnloadTexture(tex);

    UnloadModel(model);
    CloseWindow();
}
