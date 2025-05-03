pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                // Checkout code from GitHub
                git 'https://github.com/Whtiey1811/GithubAssignment'
            }
        }
        
        stage('Build') {
            steps {
                // Run Makefile
                script {
                    if (isUnix()) {
                        sh 'make'  // For Linux or Unix systems
                    } else {
                        bat 'make' // For Windows systems
                    }
                }
            }
        }

        stage('Test') {
            steps {
                // Add test commands if needed
            }
        }
    }
}
