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
        stage('Upload to Nexus') {
            steps {
                withCredentials([usernamePassword(credentialsId: 'YOUR_CREDENTIALS_ID', usernameVariable: 'NEXUS_USER', passwordVariable: 'NEXUS_PASS')]) {
                    bat '''
                        curl -u %NEXUS_USER%:%NEXUS_PASS% --upload-file myprogram.exe http://localhost:8081/repository/cpp-artifacts/myprogram.exe
                    '''
                }
            }
        }
    }
}
