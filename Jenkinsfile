pipeline {
    agent any
    stages {
        stage('Checkout') {
            steps {
                // Checkout the code from the GitHub repository
                git 'https://github.com/Whtiey1811/GithubAssignment'
            }
        }
        stage('Build') {
            steps {
                // Run the Makefile to build the C++ project
                bat 'make'
            }
        }
        stage('Test') {
            steps {
                // Add any testing steps here (optional for C++ project)
                echo 'Running tests...'
            }
        }
    }
}

