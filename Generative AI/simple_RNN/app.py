import streamlit as st
import numpy as np
import pickle
from tensorflow.keras.models import load_model
from tensorflow.keras.preprocessing.sequence import pad_sequences

# -------------------------------
# Load model and tokenizer
# -------------------------------
model = load_model("sentiment_model.h5")

with open("tokenizer.pkl", "rb") as f:
    tokenizer = pickle.load(f)

MAX_LEN = 200   # same as training

# -------------------------------
# Streamlit UI
# -------------------------------
st.set_page_config(page_title="Sentiment Analysis App", layout="centered")

st.title("🧠 Sentiment Analysis Web App")
st.write("Binary Classification (Positive / Negative)")
st.write("Model Accuracy: **64%**")

# Text input
user_text = st.text_area("Enter your review or sentence:", height=150)

# Prediction button
if st.button("Predict Sentiment"):

    if len(user_text.strip()) == 0:
        st.warning("Please enter some text.")
    else:
        # Tokenization
        seq = tokenizer.texts_to_sequences([user_text])
        padded = pad_sequences(seq, maxlen=MAX_LEN, padding="post")

        # Prediction
        pred = model.predict(padded)[0][0]

        # Decision threshold
        sentiment = "Positive 😊" if pred > 0.5 else "Negative 😞"

        # Display result
        st.subheader("Prediction Result")
        st.write("Sentiment:", sentiment)
        st.write("Confidence Score:", round(float(pred), 3))
