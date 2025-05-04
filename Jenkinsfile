pipeline {
    agent any
    environment {
        NEXUS_CREDS = credentials('nexus-creds')
        NEXUS_URL = 'http://localhost:8081/repository/cpp-artifacts/'
    }
    stages {
        stage('Checkout') {
            steps {
                git 'https://github.com/Whtiey1811/GithubAssignment'
            }
        }
        stage('Build') {
            steps {
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
                script {

                    def nexusUsername = NEXUS_CREDS_USR
                    def nexusPassword = NEXUS_CREDS_PSW

                    sh """
                        curl -u ${nexusUsername}:${nexusPassword} --upload-file target/myprogram.exe \
                            ${NEXUS_URL}/myprogram.exe
                    """
                }
            }
        }
    }
}
