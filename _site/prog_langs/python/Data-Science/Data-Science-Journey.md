# Data Science Journey

after roaming around here and there for days, searching for the right tools for data science i have decided upon learning pandas and other tools for data analysis from YouTube and the main machine learning and deep learning from this book called `Hands on with machine learning with sckit-learn and tensorflow`

This book offers amazing explanations with "at home" feeling from the author and is recommended by many

I aim to finish this book by July 19 and this is a self imposed target i aim on achieving come what may

after that I will enter maintenance and practice mode while learning some other skill and practicing this skill

I have also decided to include learnings and points to the remember in this diary. this is done using `this`

#### Now i will define what all I plan to do by 19th July

### Tasks

- [x] Finish the Data analysis with python

- [ ] The book with solving the exercises 

- [ ] Learn image recognition (possibly, if it does not need high performant gpu)

---

# 1 july

okay so i started with learning numpy and pandas and matplotlib.

finaally understood what pandas.DataFrame.**loc** and **iloc** is. it stands for locate and it gives the element value of the array contained. eg `num[2][3] = 4`, then `loc(2,3) = 4`

# 2 july

didn't get much done today.
couldn't even complete chapter 2. will start again tomorrow.
although chapter 2 is important and requires alot of practice

`note that the score on the training set is still much lower than on the validation sets, meaning that the model is still overfitting the training set. Possible solutions for overfitting are to simplify the model, constrain it (i.e., regularize it), or get a lot more training data.`

`You can easily save Scikit-Learn models by using Python’s pickle module or by using the joblib library, which is more efficient at serializing large NumPy arrays (you can install this library using pip):`

```python
import joblib joblib . dump ( my_model , "my_model.pkl" )
# and later... 
my_model_loaded = joblib . load ( "my_model.pkl" )```
```

# 6 july

I didn't quiet get the pd.cut feature earlier and then i took a break. However today when I reviewed it i got stuck on the same problem! i am sort of happy on this (am I supposed to be? Idk, but I am)

pd.cut basically sorts data into grouped-range values (or bins). for eg when taking a data set of ages, bin can separate into 0-4, 5-9, 10-14 etc
