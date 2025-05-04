pipeline {
    agent any
    
    environment {
        // Define paths for Windows
        NEXUS_URL = 'http://localhost:8081/repository/cpp-artifacts/'
        NEXUS_CREDENTIALS = credentials('nexus-creds') // Jenkins Nexus credentials
    }
    
    stages {
        stage('Checkout') {
            steps {
                git 'https://github.com/Whtiey1811/GithubAssignment'
            }
        }
        
        stage('Build') {
            steps {
                script {
                    // Ensure you're using the right make tool for Windows (MinGW, Cygwin, etc.)
                    bat 'make'  // Use 'bat' command for Windows
                }
            }
        }
        
        stage('Publish Artifact') {
            steps {
                script {
                    // If you're using Maven, you can configure it for Windows paths here:
                    bat 'mvn deploy -DrepositoryId=nexus -Durl=http://localhost:8081/repository/cpp-artifacts/'
                }
            }
        }
    }
    
    post {
        success {
            echo 'Build and deploy completed successfully!'
        }
        failure {
            echo 'Build or deploy failed.'
        }
    }
}
