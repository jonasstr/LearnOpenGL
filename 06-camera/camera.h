#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include "glm/common.hpp"
#include "glm/fwd.hpp"

class Camera {

public:

    const float movementSpeed = 3.5f;
    const float mouseSensitivity = 0.05f;
    const float scrollSensitivity = 2.5f;

    enum class Direction {
        FORWARD, BACKWARD, LEFT, RIGHT
    };

private:
    glm::vec3 position, worldUp, up, front{glm::vec3(0, 0, 0)}, right{glm::vec3(0, 0, 0)};
    float pitch, yaw;

public:

    float fov = 45.0f;
    // Constructs a camera at the given position, with pitch and yaw rotation values
    // and a world vector facing upwards.
    Camera(const glm::vec3 &position = glm::vec3(0.0f, 0.0f, 0.0f),
           const glm::vec3 &worldUp = glm::vec3(0.0f, 1.0f, 0.0f),
           float pitch = 0.0f, float yaw = -90.f);

    // Returns the view matrix of this camera using Euler angles and the lookAt matrix.
    glm::mat4 getViewMatrix() const;

    // Process mouse movement to update pitch and yaw.
    void processMouseMovement(float xOffset, float yOffset, bool constraintPitch = true);

    // Process mouse wheel to update FOV/zoom.
    void processMouseScroll(float yOffset);

    // Move the camera gradually in the given direction.
    void move(Direction direction, float deltaTime);

private:
    // Updates the new front vector from the (updated) angles.
    void update();
};