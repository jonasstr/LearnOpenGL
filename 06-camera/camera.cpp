
#include "camera.h"

using Direction = Camera::Direction;

Camera::Camera(const glm::vec3 &position,
               const glm::vec3 &worldUp,
               float pitch,
               float yaw) :
        position(position), worldUp(worldUp), pitch(pitch), yaw(yaw) {

    update();
}

glm::mat4 Camera::getViewMatrix() const {
    return glm::lookAt(position, position + front, up);
}

void Camera::move(Camera::Direction direction, float deltaTime) {

    float velocity = movementSpeed * deltaTime;
    switch (direction) {
        case Direction::FORWARD:
            position += front * velocity;
            break;
        case Direction::BACKWARD:
            position -= front * velocity;
            break;
        case Direction::LEFT:
            position -= right * velocity;
            break;
        case Direction::RIGHT:
            position += right * velocity;
            break;
    }
}

void Camera::processMouseMovement(float xOffset, float yOffset, bool constraintPitch) {

    yaw += xOffset * mouseSensitivity;
    pitch += yOffset * mouseSensitivity;

    if (constraintPitch) {
        if (pitch > 89.0f)
            pitch = 89.0f;
        if (pitch < -89.0f)
            pitch = -89.0f;
    }
    yaw = glm::mod(yaw, 360.0f);

    update();
}

void Camera::processMouseScroll(float yOffset) {

    if (fov >= 1.0f && fov <= 45.0f)
        fov -= yOffset * scrollSensitivity;
    if (fov <= 1.0f)
        fov = 1.0f;
    if (fov >= 45.0f)
        fov = 45.0f;
}


void Camera::update() {
    // Calculate front vector.
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(front);
    // Calculate right vector.
    right = glm::normalize(glm::cross(front, worldUp));
    up = glm::normalize(glm::cross(right, front));
}
