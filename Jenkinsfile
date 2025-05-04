pipeline {
    agent any
    
    environment {
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
                    bat 'make' 
                }
            }
        }
        
        stage('Publish Artifact') {
            steps {
                script {
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
