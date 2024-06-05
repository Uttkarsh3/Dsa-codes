import React, { useState, useEffect } from 'react';

const Form = () => {
  const [formValues, setFormValues] = useState({ username: '', password: '' });
  const [formErrors, setFormErrors] = useState({});
  const [isSubmitting, setIsSubmitting] = useState(false);
  const [isSubmitted, setIsSubmitted] = useState(false);

  const handleChange = (e) => {
    const { name, value } = e.target;
    setFormValues({
      ...formValues,
      [name]: value,
    });
    setFormErrors({});
    setIsSubmitted(false);
  };

  const validate = (values) => {
    const errors = {};
    if (!values.username) {
      errors.username = 'Username is required';
    } else if (values.username.length < 5) {
      errors.username = 'Username must be at least 5 characters';
    }

    if (!values.password) {
      errors.password = 'Password is required';
    } else if (values.password.length < 6) {
      errors.password = 'Password must be at least 6 characters';
    }

    return errors;
  };

  const handleSubmit = (e) => {
    e.preventDefault();
    setFormErrors(validate(formValues));
    setIsSubmitting(true);
  };

  useEffect(() => {
    if (Object.keys(formErrors).length === 0 && isSubmitting) {
      console.log('Form Submitted Successfully:', formValues);
      setIsSubmitting(false); // Reset submitting state after successful submission
      setIsSubmitted(true); // Set submitted state to true after successful submission
      // Here you can handle form submission, e.g., send data to an API
    }
  }, [formErrors, isSubmitting, formValues]);

  return (
    <div>
      {isSubmitted ? (
        <p>Form Submitted Successfully!</p>
      ) : (
        <form onSubmit={handleSubmit}>
          <div>
            <label>Username</label>
            <input
              type="text"
              name="username"
              value={formValues.username}
              onChange={handleChange}
            />
            {formErrors.username && <p>{formErrors.username}</p>}
          </div>
          <div>
            <label>Password</label>
            <input
              type="password"
              name="password"
              value={formValues.password}
              onChange={handleChange}
            />
            {formErrors.password && <p>{formErrors.password}</p>}
          </div>
          <button type="submit">Submit</button>
        </form>
      )}
    </div>
  );
};

export default Form;
