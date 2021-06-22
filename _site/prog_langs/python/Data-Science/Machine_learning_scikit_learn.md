# Machine Learning with sckit-learn

## 1. import pandas and load the dataset

pandas is a library made for statistical computations. It is based off of numpy

```python
import pandas as pd
file_path = 'path/to/file.csv'
my_data = pd.read_csv(file_path)
```

You can inspect the data using head(), describe() and column. 

```python
my_data.head()    # Give the First 5 data for each columns
my_data.describe() # Show the whole data set
my_data.columns    # show the tilte for each columns
```

## 2. Select the prediction target

the prediction target is **what you want to predict**

'y' is conventionally used for this

```python
y = my_data.Prediction_target
```

## 3. Choosing the "Features"

The features are aspects of the data which influence the prediction.

For eg if you are predicting House Price, the locality, size of house, floor it is on, will all affect/influence it's price.

It is generally stored in a list, and are strings which are headings of the columns.

Further the **dataset** is stored conventionally in 'X' as follows

```python
Features = ['feature1', 'feature2', 'feature3', 'feature4']
X = my_data[Features] 
```

## 4. Building Your Model

The steps to building and using a model are:

- **Define:** What type of model will it be? A decision tree? Some other type of model? Some other parameters of the model type are specified too.
- **Fit:** Capture patterns from provided data. This is the heart of modeling.
- **Predict:** Just what it sounds like
- **Evaluate**: Determine how accurate the model's predictions are.

Here is an example of defining a decision tree model with scikit-learn and fitting it with the features and target variable.

```python
from sklearn.tree import DecisionTreeRegressor

# Define model. Specify a number for random_state to ensure same results each run
melbourne_model = DecisionTreeRegressor(random_state=1)

# Fit model
melbourne_model.fit(X, y)
# X is the "Training input samples"
# y is the target values (real numbers)
```

Many machine learning models allow some randomness in model training. Specifying a number for `random_state` ensures you get the same results in each run. This is considered a good practice. You use any number, and model quality won't depend meaningfully on exactly what value you choose.

We now have a fitted model that we can use to make predictions.

We can Check the predictions for the **First 5 datum as follows**

```python
print("Making predictions for the following 5 houses:")
print(X.head())
print("The predictions are")
print(melbourne_model.predict(X.head()))
# The "fit" method takes X as a parameter which is the input samples
# It returns an array of predicted classes
```

## Validating with Mean Avg Error

Higher the error, worse the model.

```python
from sklearn.metrics import mean_absolute_error

predicted_home_prices = melbourne_model.predict(X)
mean_absolute_error(y, predicted_home_prices)
```

## Test-Train Split

The scikit-learn library has a function `train_test_split` to break up the data into two pieces. We'll use some of that data as training data to fit the model, and we'll use the other data as validation data to calculate `mean_absolute_error`.

```python
from sklearn.model_selection import train_test_split

# split data into training and validation data, for both features and target
# The split is based on a random number generator. Supplying a numeric value to
# the random_state argument guarantees we get the same split every time we
# run this script.
train_X, val_X, train_y, val_y = train_test_split(X, y, random_state = 0)
# Define model
melbourne_model = DecisionTreeRegressor()
# Fit model
melbourne_model.fit(train_X, train_y)

# get predicted prices on validation data
val_predictions = melbourne_model.predict(val_X)
print(mean_absolute_error(val_y, val_predictions))
```

### Models can suffer from either:

- **Overfitting:** capturing spurious patterns that won't recur in the future, leading to less accurate predictions, or
- **Underfitting:** failing to capture relevant patterns, again leading to less accurate predictions.

We use **validation** data, which isn't used in model training, to measure a candidate model's accuracy. This lets us try many candidate models and keep the best one.

```python
def get_mae(max_leaf_nodes, train_X, val_X, train_y, val_y):
    model = DecisionTreeRegressor(max_leaf_nodes=max_leaf_nodes, random_state=0)
    model.fit(train_X, train_y)
    preds_val = model.predict(val_X)
    mae = mean_absolute_error(val_y, preds_val)
    return(mae)
```

* `DecisionTreeRegressor()` takes an optional value called `max_leaf_nodes` which specifies the number of nodes or 'leafs' that the model should have

## Random Forests

Decision trees leave you with a difficult decision. A deep tree with lots of leaves will overfit because each prediction is coming from historical data from only the few houses at its leaf. But a shallow tree with few leaves will perform poorly because it fails to capture as many distinctions in the raw data.

Even today's most sophisticated modeling techniques face this tension between underfitting and overfitting. But, many models have clever ideas that can lead to better performance. We'll look at the **random forest** as an example.

The random forest uses many trees, and it makes a prediction by averaging the predictions of each component tree. It generally has much better predictive accuracy than a single decision tree and it works well with default parameters. If you keep modeling, you can learn more models with even better performance, but many of those are sensitive to getting the right parameters.

```python
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_absolute_error

forest_model = RandomForestRegressor(random_state=1)
forest_model.fit(train_X, train_y)
melb_preds = forest_model.predict(val_X)
print(mean_absolute_error(val_y, melb_preds))
```

## Another Example

```python
y = train_data["Survived"]

features = ["Pclass", "Sex", "SibSp", "Parch"]
X = pd.get_dummies(train_data[features])
X_test = pd.get_dummies(test_data[features])

model = RandomForestClassifier(n_estimators=100, max_depth=5, random_state=1)
model.fit(X, y)
predictions = model.predict(X_test)

output = pd.DataFrame({'PassengerId': test_data.PassengerId, 'Survived': predictions})
```

## Dealing with Missing Values

* ### Dropping missing Values
  
  One way to deal with missing data is to drop the tables with missing values, for eg
  
  ```python
  cols_with_missing = [col for col in X_train.columns
                       if X_train[col].isnull().any()]
  
  # Drop columns in training and validation data
  reduced_X_train = X_train.drop(cols_with_missing, axis=1)
  reduced_X_valid = X_valid.drop(cols_with_missing, axis=1)
  ```

* ### Using Imputation
  
  We can use imputation to deal with `NULL` or `NaN` values and is done as follows:

```python
from sklearn.impute import SimpleImputer

# Imputation
my_imputer = SimpleImputer()
imputed_X_train = pd.DataFrame(my_imputer.fit_transform(X_train))
imputed_X_valid = pd.DataFrame(my_imputer.transform(X_valid))

# Imputation removed column names; put them back
imputed_X_train.columns = X_train.columns
imputed_X_valid.columns = X_valid.columns

print("MAE from Approach 2 (Imputation):")
print(score_dataset(imputed_X_train, imputed_X_valid, y_train, y_valid))
```

In this method we fill in the missing values with mean values. Other values can also be inserted but the performance difference usually negligible.

* ### Imputation Part Deux
  
  Another way is to impute as well as record what values were imputed. This is done by adding another column to the dataset.

```python
# Make copy to avoid changing original data (when imputing)
X_train_plus = X_train.copy()
X_valid_plus = X_valid.copy()

# Make new columns indicating what will be imputed
for col in cols_with_missing:
    X_train_plus[col + '_was_missing'] = X_train_plus[col].isnull()
    X_valid_plus[col + '_was_missing'] = X_valid_plus[col].isnull()

# Imputation
my_imputer = SimpleImputer()
imputed_X_train_plus = pd.DataFrame(my_imputer.fit_transform(X_train_plus))
imputed_X_valid_plus = pd.DataFrame(my_imputer.transform(X_valid_plus))

# Imputation removed column names; put them back
imputed_X_train_plus.columns = X_train_plus.columns
imputed_X_valid_plus.columns = X_valid_plus.columns

print("MAE from Approach 3 (An Extension to Imputation):")
print(score_dataset(imputed_X_train_plus, imputed_X_valid_plus, y_train, y_valid))
```

## Categorical Variables

we have three main approaches for categorical Data

* ### Drop Categorical Variables
  
  The easiest approach to dealing with categorical variables is to simply remove them from the dataset. This approach will only work well if the columns did not contain useful information.
  
  eg
  
  ```python
  # Get list of categorical variables
  s = (X_train.dtypes == 'object')
  object_cols = list(s[s].index)
  
  print("Categorical variables:")
  print(object_cols)
  ```
  
  We drop the `object` columns with the [`select_dtypes()`](https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.DataFrame.select_dtypes.html) method.
  
  ```python
  drop_X_train = X_train.select_dtypes(exclude=['object'])
  drop_X_valid = X_valid.select_dtypes(exclude=['object'])
  
  print("MAE from Approach 1 (Drop categorical variables):")
  print(score_dataset(drop_X_train, drop_X_valid, y_train, y_valid))
  ```

* ### Label Encoding
  
  **Label encoding** assigns each unique value to a different integer.
  
   Not all categorical variables have a clear ordering in the values, but we refer to those that do as **ordinal variables**. For tree-based models (like decision trees and random forests), you can expect label encoding to work well with ordinal variables.
  
  This assumption makes sense in this example, because there is an indisputable ranking to the categories. Not all categorical variables have a clear ordering in the values, but we refer to those that do as **ordinal variables**. For tree-based models (like decision trees and random forests), you can expect label encoding to work well with ordinal variables.
  
  ```python
  from sklearn.preprocessing import LabelEncoder
  
  # Make copy to avoid changing original data 
  label_X_train = X_train.copy()
  label_X_valid = X_valid.copy()
  
  # Apply label encoder to each column with categorical data
  label_encoder = LabelEncoder()
  for col in object_cols:
      label_X_train[col] = label_encoder.fit_transform(X_train[col])
      label_X_valid[col] = label_encoder.transform(X_valid[col])
  
  print("MAE from Approach 2 (Label Encoding):") 
  print(score_dataset(label_X_train, label_X_valid, y_train, y_valid))
  ```
  
  **One-hot encoding** creates new columns indicating the presence (or absence) of each possible value in the original data
  
  In the original dataset, "Color" is a categorical variable with three categories: "Red", "Yellow", and "Green". The corresponding one-hot encoding contains one column for each possible value, and one row for each row in the original dataset. Wherever the original value was "Red", we put a 1 in the "Red" column; if the original value was "Yellow", we put a 1 in the "Yellow" column, and so on.
  
  In contrast to label encoding, one-hot encoding *does not* assume an ordering of the categories. Thus, you can expect this approach to work particularly well if there is no clear ordering in the categorical data (e.g., "Red" is neither *more* nor *less* than "Yellow"). We refer to categorical variables without an intrinsic ranking as **nominal variables**.
  
  One-hot encoding generally does not perform well if the categorical variable takes on a large number of values (i.e., you generally won't use it for variables taking more than 15 different values).
  
  We use the [`OneHotEncoder`](https://scikit-learn.org/stable/modules/generated/sklearn.preprocessing.OneHotEncoder.html) class from scikit-learn to get one-hot encodings. There are a number of parameters that can be used to customize its behavior.
  
  - We set `handle_unknown='ignore'` to avoid errors when the validation data contains classes that aren't represented in the training data, and
  - setting `sparse=False` ensures that the encoded columns are returned as a numpy array (instead of a sparse matrix).
  
  To use the encoder, we supply only the categorical columns that we want to be one-hot encoded. For instance, to encode the training data, we supply `X_train[object_cols]`. (`object_cols` in the code cell below is a list of the column names with categorical data, and so `X_train[object_cols]` contains all of the categorical data in the training set.)
  
  ```python
  from sklearn.preprocessing import OneHotEncoder
  
  # Apply one-hot encoder to each column with categorical data
  OH_encoder = OneHotEncoder(handle_unknown='ignore', sparse=False)
  OH_cols_train = pd.DataFrame(OH_encoder.fit_transform(X_train[object_cols]))
  OH_cols_valid = pd.DataFrame(OH_encoder.transform(X_valid[object_cols]))
  
  # One-hot encoding removed index; put it back
  OH_cols_train.index = X_train.index
  OH_cols_valid.index = X_valid.index
  
  # Remove categorical columns (will replace with one-hot encoding)
  num_X_train = X_train.drop(object_cols, axis=1)
  num_X_valid = X_valid.drop(object_cols, axis=1)
  
  # Add one-hot encoded columns to numerical features
  OH_X_train = pd.concat([num_X_train, OH_cols_train], axis=1)
  OH_X_valid = pd.concat([num_X_valid, OH_cols_valid], axis=1)
  
  print("MAE from Approach 3 (One-Hot Encoding):") 
  print(score_dataset(OH_X_train, OH_X_valid, y_train, y_valid))
  ```
