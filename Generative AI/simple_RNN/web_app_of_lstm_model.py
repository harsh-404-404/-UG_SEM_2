import pandas as pd
import numpy as np
import tensorflow as tf
from tensorflow.keras.preprocessing.text import Tokenizer
from tensorflow.keras.preprocessing.sequence import pad_sequences
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Embedding, SimpleRNN, Dense
from sklearn.model_selection import train_test_split
import pickle
import streamlit as st
# Load model
model = tf.keras.models.load_model("sentiment_model.h5")

# Load tokenizer
with open("tokenizer.pkl", "rb") as f:
    tokenizer = pickle.load(f)

max_length = 200   # same length used during training

st.title("Sentiment Analysis App")
st.write("Enter a sentence to predict sentiment")

# Text input
user_input = st.text_area("Enter Text")

if st.button("Predict Sentiment"):

    if user_input != "":

        # Convert text to sequence
        sequence = tokenizer.texts_to_sequences([user_input])

        # Padding
        padded = pad_sequences(sequence, maxlen=max_length)

        # Prediction
        prediction = model.predict(padded)

        if prediction[0][0] > 0.5:
            st.success("Positive Sentiment 😊")
        else:
            st.error("Negative Sentiment 😠")