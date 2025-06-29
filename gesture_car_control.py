import cv2
import mediapipe as mp
import requests

ESP32_IP = "http://192.168.1.10"  # <-- Replace with your ESP32 IP

cap = cv2.VideoCapture("http://192.168.1.12:8080/video")


mp_hands = mp.solutions.hands
hands = mp_hands.Hands()
mp_draw = mp.solutions.drawing_utils

def count_fingers(hand_landmarks):
    count = 0
    tips = [8, 12, 16, 20]
    for tip in tips:
        if hand_landmarks.landmark[tip].y < hand_landmarks.landmark[tip - 2].y:
            count += 1
    # Thumb
    if hand_landmarks.landmark[4].x > hand_landmarks.landmark[3].x:
        count += 1
    return count

prev_count = -1

while True:
    success, img = cap.read()
    img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    results = hands.process(img_rgb)

    if results.multi_hand_landmarks:
        for handLms in results.multi_hand_landmarks:
            mp_draw.draw_landmarks(img, handLms, mp_hands.HAND_CONNECTIONS)
            finger_count = count_fingers(handLms)

            if finger_count != prev_count:
                print("Sending gesture:", finger_count)
                try:
                    requests.get(f"{ESP32_IP}/{finger_count}")
                except:
                    print("Failed to send request")
                prev_count = finger_count

    cv2.imshow("Gesture Detection", img)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
